#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	pii p[200005];
	while(t--){
		int n;
		scanf("%d",&n);
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			int l,r;
			scanf("%d %d",&l,&r);
			p[i]=mp(l,r);
			v.pb(mp(l,1));
			v.pb(mp(r+1,-1));
		}
		int split=-1;
		int sum=0;
		sort(v.begin(),v.end());
		int last=v.back().x;
		for(auto it:v){
			sum+=it.y;
			if(sum==0){
				split=it.x;
				break;
			}
		} 
		if(split==last)printf("-1\n");
		else{
			for(int i=0;i<n;i++){
				if(p[i].y<split)printf("1 ");
				else printf("2 ");
			}
			printf("\n");
		}
	}
}