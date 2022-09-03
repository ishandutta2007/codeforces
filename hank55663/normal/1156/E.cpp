#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int loc[200005];
int p[200005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&p[i]);
		loc[p[i]]=i;
	}
	set<int> s;
	s.insert(0);
	s.insert(n+1);
	int ans=0;
	for(int i =n;i>=1;i--){
		auto it=s.upper_bound(loc[i]);
		int r=*it-1;
		it--;
		int l = *it+1;
		if(r-loc[i]<loc[i]-l){
			for(int j =loc[i]+1;j<=r;j++){
				int need=i-p[j];
				if(need>0&&loc[need]<loc[i]&&loc[need]>=l)ans++;
			}
		}
		else{
			for(int j = l;j<loc[i];j++){
				int need=i-p[j];
				if(need>0&&loc[need]>loc[i]&&loc[need]<=r)ans++;
			}
		}
		s.insert(loc[i]);
	}
	printf("%d\n",ans);
}