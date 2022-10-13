#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int hp[2],cooldown[2],minDamage[2],maxDamage[2],prob[2],rangeDamage[2],turn[66],T;
double f[222][222][66],s0[222][222][66],s1[222][222][66];

int main()
{
	for (int i=0;i<2;i++) 
	{
		cin >> hp[i] >> cooldown[i] >> minDamage[i] >> maxDamage[i] >> prob[i];
		rangeDamage[i]=maxDamage[i]-minDamage[i]+1;
	}
	
	for (int t=0;;t++)
		if (t && t%cooldown[0]==0 && t%cooldown[1]==0) break;
		else
		{
			if (t%cooldown[0]==0) turn[T++]=0;
			if (t%cooldown[1]==0) turn[T++]=1;
		}
	
	double unchangedProb=1.0;
	for (int t=0;t<T;t++) unchangedProb*=0.01*prob[turn[t]];
	
	for (int hp0=1;hp0<=hp[0];hp0++)
		for (int hp1=1;hp1<=hp[1];hp1++)
		{
			for (int t=0;t<T;t++)
				if (!turn[t])
				{
					int tt=(t+1)%T,limDamage=min(maxDamage[0],hp1-1);
					if (minDamage[0]<=limDamage)
						f[hp0][hp1][t]+=s1[hp0][hp1-minDamage[0]][tt]-s1[hp0][hp1-limDamage-1][tt];
					f[hp0][hp1][t]+=min(rangeDamage[0],maxDamage[0]-limDamage);
					f[hp0][hp1][t]*=0.01*(100-prob[0])/rangeDamage[0];
					
				}
				else
				{
					int tt=(t+1)%T,limDamage=min(maxDamage[1],hp0-1);
					if (minDamage[1]<=limDamage)
						f[hp0][hp1][t]+=s0[hp0-minDamage[1]][hp1][tt]-s0[hp0-limDamage-1][hp1][tt];
					f[hp0][hp1][t]*=0.01*(100-prob[1])/rangeDamage[1];
				}
			// missed shot	
			double coefficient=1.0;
			for (int t=1;t<T;t++)
			{
				coefficient*=0.01*prob[turn[t-1]];
				f[hp0][hp1][0]+=coefficient*f[hp0][hp1][t];	
			}
			f[hp0][hp1][0]/=(1-unchangedProb); // calculate lim
			s0[hp0][hp1][0]=s0[hp0-1][hp1][0]+f[hp0][hp1][0];
			s1[hp0][hp1][0]=s1[hp0][hp1-1][0]+f[hp0][hp1][0];
			for (int t=T-1;t;t--)
			{
				f[hp0][hp1][t]+=f[hp0][hp1][(t+1)%T]*0.01*prob[turn[t]];
				s0[hp0][hp1][t]=s0[hp0-1][hp1][t]+f[hp0][hp1][t];
				s1[hp0][hp1][t]=s1[hp0][hp1-1][t]+f[hp0][hp1][t];
			}
		}
	
	printf("%.9lf\n",f[hp[0]][hp[1]][0]);
}