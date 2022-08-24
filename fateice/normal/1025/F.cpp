#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define pi acos(-1.0)
#define ll long long
using namespace std;
 
int n,c[2][3],blg[10005];
struct point{ int x,y,c,id; double k; }p[10005];
bool cmp(point x,point y){ return x.k<y.k; }
int main(){
	scanf("%d",&n); int i,j,k;
	for (i=1; i<=n; i++) scanf("%d%d",&p[i].x,&p[i].y),p[i].c=0;
	for (i=1; i<=n; i++) p[i].id=i;
	point o; ll tmp,ans=0;
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++) if (p[j].id==i) break;
		o=p[j]; k=o.c;
		for (j=1; j<=n; j++){
			p[j].k=(p[j].id!=i)?atan2(p[j].y-o.y,p[j].x-o.x):1e100;
			if (p[j].k<=0) p[j].k+=pi;
		}
		sort(p+1,p+n+1,cmp);
		memset(c,0,sizeof(c));
		for (j=1; j<n; j++)
			if (p[j].y<o.y || p[j].y==o.y && p[j].x>o.x){
				c[0][p[j].c]++; blg[j]=0;
			} else{
				c[1][p[j].c]++; blg[j]=1;
			}
		for (j=1; j<n; j++){
			c[blg[j]][p[j].c]--;// tmp=1;
			/*if (k) tmp*=c[0][0]; if (p[j].c) tmp*=c[1][0];
			if (k^1) tmp*=c[0][1]; if (p[j].c^1) tmp*=c[1][1];
			if (k^2) tmp*=c[0][2]; if (p[j].c^2) tmp*=c[1][2];*/
			tmp=(ll)c[0][0]*(c[0][0]-1)*c[1][0]*(c[1][0]-1)/4;
			ans+=tmp;// tmp=1;
			/*if (k) tmp*=c[1][0]; if (p[j].c) tmp*=c[0][0];
			if (k^1) tmp*=c[1][1]; if (p[j].c^1) tmp*=c[0][1];
			if (k^2) tmp*=c[1][2]; if (p[j].c^2) tmp*=c[0][2];
			ans+=tmp;*/
			blg[j]^=1; c[blg[j]][p[j].c]++;
		}
	}
	printf("%lld\n",ans>>1);
	return 0;
}