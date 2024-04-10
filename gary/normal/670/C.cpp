#include<bits/stdc++.h>
using namespace std;
int n,m,maxans=-1e6,maxalmost,bestmovie;
map<int,int> num;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		num[a]+=1;
	}
	scanf("%d",&m);
	int aud[200001],subtitle[200001];
	for(int i=1;i<=m;i++){
		scanf("%d",&aud[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&subtitle[i]);
	}
	for(int i=1;i<=m;i++){
		if(num[aud[i]]==maxans){
			if(num[subtitle[i]]>maxalmost){
				maxalmost=num[subtitle[i]];
				bestmovie=i;
			}
		}
		if(num[aud[i]]>maxans){
			maxans=num[aud[i]];
			maxalmost=num[subtitle[i]];
			bestmovie=i;
		}
	}
	printf("%d\n",bestmovie);
	return 0;
}