#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[4],b[4],c[4],d[4],pla[4],plb[4],cnt[4][4],minn,maxx;
void Do(){
	minn=n;
	for(int i=1;i<=3;i++)pla[i]=i;
	do {
		for(int i=1;i<=3;i++)plb[i]=i;
		do {
			for(int i=1;i<=3;i++)c[i]=a[i],d[i]=b[i];
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					cnt[pla[i]][plb[j]]=min(c[pla[i]],d[plb[j]]);
					c[pla[i]]-=cnt[pla[i]][plb[j]],d[plb[j]]-=cnt[pla[i]][plb[j]];
				}
			}
			minn=min(minn,cnt[1][2]+cnt[2][3]+cnt[3][1]);
			maxx=max(maxx,cnt[1][2]+cnt[2][3]+cnt[3][1]);
		} while(next_permutation(plb+1,plb+4));
	} while(next_permutation(pla+1,pla+4));
}
int main(){
	cin>>n;
	for(int i=1;i<=3;i++)cin>>a[i];
	for(int i=1;i<=3;i++)cin>>b[i];
	Do();
	cout<<minn<<' '<<maxx<<endl;
}