#include<fstream>

using namespace std;

const char iname[]="input.txt";
const char oname[]="output.txt";

const int maxn=3005;

ifstream f(iname);
ofstream g(oname);

double h[maxn],r[maxn],R[maxn],H[maxn],l[maxn],rez;

int i,n,j;

double calc(int x,int y)
{
	double baza=0;
	if(r[x]>=r[y])
		baza=0+h[y];
	else
		if(r[y]>=R[x])
			baza=h[x]+h[y];
		else
   	 	{
	   	 	double aux=0;
			aux=(l[x]*R[x]-l[x]*r[y])/(double)R[x];
			aux=h[x]-aux;
			baza=aux+h[y];
		}
	double mij=0;
	if(R[y]<=R[x])
	{
		double aux=0;
		aux=(l[x]*R[x]-l[x]*R[y])/(double)R[x];
		aux=h[x]-aux;
		mij=aux;
	}
	double top=0;
	if(R[y]>R[x])
	{
		double aux=0;
		aux=(l[y]*R[y]-l[y]*R[x])/(double)R[y];
		if(aux<=h[y])
			top=aux+h[x];
	}
  //  fprintf(stderr,"%lf %lf %lf\n",baza,mij,top);
	return max(max(top,mij),baza);
}

int main()
{
	f>>n;
	for(i=1;i<=n;++i)
		f>>h[i]>>r[i]>>R[i],l[i]=(R[i]*h[i])/(double)(R[i]-r[i]);
	H[1]=h[1];
	rez=h[1];
	for(i=2;i<=n;++i)
	{
		for(j=1;j<i;++j)
			H[i]=max(H[i],H[j]-h[j]+calc(j,i));
		rez=max(rez,H[i]);
	}

	g.setf(ios::fixed,ios::floatfield);
	g.precision(8);
	g<<rez<<"\n";
}