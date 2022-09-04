#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
string change(string s,int x){
	string hi=s.substr(s.size()-x,x);
	reverse(hi.begin(),hi.end());
	s=hi+s.substr(0,s.size()-x);
	//cout<<x<<s<<endl;
	return s;
}
int main(){
	int n;
	scanf("%d",&n);
	string s,t;
	cin>>s;
	cin>>t;
	int cnts[26],cntt[26];
	MEM(cnts);
	MEM(cntt);
	for(int i=0;s[i]!=0;i++)
	cnts[s[i]-'a']++;
	for(int i=0;t[i]!=0;i++)
	cntt[t[i]-'a']++;
	for(int i=0;i<26;i++){
		if(cnts[i]!=cntt[i]){
			printf("-1\n");
			return 0;
		}
	}
	int now=n/2,a=n/2-1,b=n/2+1;
	vector<int> v;
	for(int i=0;i<n;i++){
		v.pb(i);
		s=change(s,i);
		for(int j=n-1;j>=0;j--){
			if(s[j]==t[now]){
				v.pb(n-j);
				s=change(s,n-j);
				v.pb(j-i);
				s=change(s,j-i);
				break;
			}
		}
		if(i%2==0)
		now=a,a--;
		else
		now=b,b++;
	//	printf("%d\n",i);
	}
	if(n%2==1)
	v.pb(n);
	s=change(s,n);
	printf("%d\n",v.size());
	for(auto it:v)
	printf("%d ",it);

}