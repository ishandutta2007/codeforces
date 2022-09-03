#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
map<int,int> ma[200005];
int cnt[200005];
int main(){
	int n,m,Q;
	scanf("%d %d %d",&n,&m,&Q);
	int loc[200005];
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		loc[x]=i;
		//scanf("%d",&b[i]);
	}
//	last[b[0]]=b[n-1];
/*	for(int i =1;i<n;i++){
		last[b[i]]=b[i-1];
	}*/
	int a[200005];
	for(int i = 0;i<m;i++){
		scanf("%d",&a[i]);
		a[i]=loc[a[i]];
	}
	fill(cnt,cnt+n+1,0);
	int l=-1;
	int ans[200005];
	for(int i = 0;i<m;i++){
		int last=(a[i]+n-1)%n;
		int now=a[i];
		//ma[last],ma[now]
		if(ma[last].size()>ma[now].size()){
			for(pair<int,int> it:ma[now]){
				it.x=cnt[now]-it.x-1;
				it.x=cnt[last]-it.x;
				if(ma[last].find(it.x)!=ma[last].end()){
					ma[last][it.x]=max(ma[last][it.x],it.y);
				}
				else{
					ma[last][it.x]=it.y;
				}
			}
			ma[now].clear();
			swap(ma[last],ma[now]);
			cnt[now]=cnt[last]+1;
			cnt[last]=0;
		}
		else{
			for(pair<int,int> it:ma[last]){
				it.x=cnt[last]-it.x+1;
				it.x=cnt[now]-it.x;
				if(ma[now].find(it.x)!=ma[now].end()){
					ma[now][it.x]=max(ma[now][it.x],it.y);
				}
				else{
					ma[now][it.x]=it.y;
				}
			}
			ma[last].clear();
		}
		int mycnt=cnt[a[i]];
		ma[now][mycnt-1]=i;
		while(cnt[now]-ma[now].begin()->x==n){
			l=max(l,ma[now].begin()->y);
			ma[now].erase(ma[now].begin());
		}
		ans[i+1]=l+1;
		//printf("%d ",l+1);
	}
//	printf("\n");
	while(Q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(ans[r]>=l){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}