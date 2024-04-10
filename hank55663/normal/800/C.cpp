//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int isprime[200005];
vector<int> prime;
void find(){
	MEM(isprime);
	for(int i=2;i<200005;i++)
	if(!isprime[i]){
		prime.pb(i);
		for(int j=i;j<200005;j++){
			isprime[j]=i;
		}
	}
}
pll gcd(LL a, LL b){
    if(b == 0) return make_pair(1, 0);
    else{
        int p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.second, q.first - q.second * p);
    }
}
LL div(LL a,LL b,LL m){
	pll p=gcd(b,m);
	return ((a/__gcd(b,m)*(p.x%m))%m+m)%m;
}
int main(){
	int n,m;
	int dp[200005];
	MEM(dp);
	scanf("%d %d",&n,&m);
	set<int> s;
	for(int i=1;i<m;i++)
	if(m%i==0)
	s.insert(i);
	s.insert(m);
	map<int,vector<int> > v;
	map<int,int> last;
	map<int,int> w;
	map<int,int> val;
	map<int,set<int> > ele;
	for(int i=1;i<=m;i++){
		w[__gcd(i,m)]++;
		val[__gcd(i,m)]++;
		ele[__gcd(i,m)].insert(i); 
	}
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a==0)
		ele[m].erase(m);
		w[__gcd(m,a)]--;
		val[__gcd(m,a)]--;
		ele[__gcd(m,a)].erase(a);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		set<int>::iterator it2=it;
		it2++;
		for(;it2!=s.end();it2++)
		if(*it2%*it==0){
			v[*it].pb(*it2);
		}
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		for(vector<int>::iterator it2=v[*it].begin();it2!=v[*it].end();it2++){
			if(w[*it2]+val[*it]>=val[*it2]){
				last[*it2]=*it;
				val[*it2]=w[*it2]+val[*it];
			}
		}
	}
	printf("%d\n",val[m]);
	vector<int> ans;
	for(int i=m;i!=1;i=last[i]){
		ans.pb(i/last[i]);
	}
	ans.pb(1);
	int now=1;
	int sum=1;
	while(!ans.empty()){
		int p=ans.back();
		ans.pop_back();	
		sum*=p;
		for(set<int>::iterator it=ele[sum].begin();it!=ele[sum].end();it++){
			printf("%I64d ",div(*it,now,m));
			now=*it;
		}
	}
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/