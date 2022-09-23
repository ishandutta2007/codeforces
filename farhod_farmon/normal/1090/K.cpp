#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
char t[MAXN*10],tmp[MAXN*10];
string s[MAXN];
int arr[MAXN],id[MAXN];
map<int,int>pm;
vector<int>adj[MAXN];
pair<PII,int> res[MAXN];
int mod(ll x){
	return (x%INF);	
}
int main(){
   // freopen("file.in", "r", stdin);
    int n;
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%s",tmp,t);
		s[i]=string(tmp);
		int sz=strlen(t);
		for(int j=0;j<sz;j++)
			arr[i]|=(1<<(t[j]-'a'));
		pm[arr[i]]=1;	
	}
	int c=0;
	tr(it,pm){
		it->ss=++c;
		id[c]=it->ff;
	}
	for(int i=1;i<=n;i++)
		adj[pm[arr[i]]].pb(i);
	vector<vector<int> >ans;	
	for(int i=1;i<=c;i++){
		int mask=id[i],idx,sz,who;
		PII now;
		for(int j=0;j<int(adj[i].size());j++){
			idx=adj[i][j];
			sz=(s[idx].size());
			who=-1;now=mp(0,0);
			for(int h=sz-1;h>=0;h--)
				if(!(mask&(1<<(s[idx][h]-'a')))){
					who=h;
					break;	
				}
			for(int h=0;h<=who;h++){
				now.ff=mod(now.ff*27LL+(s[idx][h]-'a'+1));
				now.ss=mod(now.ss*47LL+(s[idx][h]-'a'+1));
			}
			res[j]=mp(now,idx);
		}
		sort(res,res+adj[i].size());
		vector<int>v;
		for(int j=0;j<adj[i].size();j++){
			if(j and res[j].ff!=res[j-1].ff){
				ans.pb(v);
				v.clear();	
			}
			v.pb(res[j].ss);
		}ans.pb(v);
	}
	printf("%d\n",int(ans.size()));
	tr(it,ans){
		printf("%d ",(*it).size());
		tr(itt,*it)
			printf("%d ",*itt);
		puts("");		
	}
	return 0;
}