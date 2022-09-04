#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n,a,b,k,f;
	scanf("%d %d %d %d %d",&n,&a,&b,&k,&f);
	pair<string,string> p[300];
	map<pair<string,string> ,int> m;
	string last="";
	int now=0;
	for(int i=0;i<n;i++){
		string s,s1;
		cin>> s>>s1;
		if(s==last){
			now+=b;
			last=s1;
			if(s>s1)
			swap(s,s1);
			m[mp(s,s1)]+=b;
		}
		else{
			now+=a;
			last=s1;
			if(s>s1)
			swap(s,s1);
			m[mp(s,s1)]+=a;
		}
		//last=s1;
	}
//	printf("%d\n",now);
	vector<int> v;
	for(map<pair<string,string> ,int>::iterator it=m.begin();it!=m.end();it++){
		v.pb(it->y);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size()&&i<k;i++){
	//	printf("%d %d\n",now,v[i]);
		if(v[i]>f){
			now-=v[i];
			now+=f;
		}
	}
	printf("%d\n",now);
}