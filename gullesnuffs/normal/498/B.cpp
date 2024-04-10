#include <bits/stdc++.h>

using namespace std;

int n, T;
int t[5005];
double p[5005];
double cp[5005];
double prob[2][5005];
float diff[5005][5005];
bool read=0, write=1;
double change[5005];

int main(){
	cin >> n >> T;
	for(int i=0; i < n; ++i){
		int P;
		cin >> P >> t[i];
		--t[i];
		p[i]=(P)/100.0;
		cp[i]=1-p[i];
		change[i]=1;
		for(int j=0; j < t[i]; ++j){
			change[i]*=(1-p[i]);
		}
	}
	p[n]=0;
	change[n]=1;
	t[n]=5001;
	prob[write][0]=1;
	diff[0][t[0]]=change[0];
	for(int i=0; i < T; ++i){
		write^=1;
		read^=1;
		prob[write][0]=0;
		for(int j=0; j <= n; ++j){
			if(j > i)
				continue;
			double rec=diff[j][i]*cp[j]+prob[read][j]*p[j];//diff[j][i]+(prob[read][j]-diff[j][i])*p[j];
			double nonrec=prob[read][j]-rec;
			prob[write][j]+=nonrec;
			prob[write][j+1]=rec;
			if(i+t[j+1] <= 5000)
				diff[j+1][i+t[j+1]+1] += rec*change[j+1];
		}
	}
	double ans=0;
	for(int i=0; i <= n; ++i)
		ans += prob[write][i]*i;
	printf("%.7lf\n", ans);
}