#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
int main(){
	int frog[100005];
	int w,L;
	scanf("%d %d",&w,&L);
	int a[100005];
	fill(frog,frog+w+1,0);
	for(int i = 1;i<w;i++)
		scanf("%d",&a[i]);
	a[w]=1e9;
	frog[0]=1e9;
	int l = 0;
	for(int i = 1;i<=w;i++){
		l=max(l,i-L);
		while(l<i&&a[i]){
			int add = min(frog[l],a[i]);
			frog[i]+=add;
			a[i]-=add;
			frog[l]-=add;
			if(frog[l]==0){
				l++;
			}
		}
		//printf("%d\n",frog[i]);
	}
	printf("%d\n",frog[w]);
}