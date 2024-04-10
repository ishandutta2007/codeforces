#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	string s;
	string t;
	cin>>s>>t;
	int cnt[26];
	MEM(cnt);
	for(auto it:s)
	cnt[it-'a']++;
	for(auto it:t){
		if(--cnt[it-'a']<0){
			printf("-1\n");
			return 0;
		}
	}
	vector<int> v;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){
			for(int j=i+1;j<n;j++){
				if(s[j]==t[i]){
					while(j!=i){
						v.pb(j);
						swap(s[j],s[j-1]);
						j--;
					}
					break;
				}
			}
		}
	}
	printf("%d\n",v.size());
	for(auto it:v)
		printf("%d ",it);
	printf("\n");
}