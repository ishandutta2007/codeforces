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
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
const LL mod =2147483647;
vector<string> v;
main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		v.clear();
		int t=0;
		string s;
		cin>>s;
		if(s=="YES")
		{
			for(int j=0;j<k;j++){
				string ss;
				char c=t/26+'A',c2=t%26+'a';
				ss=ss+c+c2;
				t++;
				v.pb(ss);
			}
		}
		else{
			string ss;
			char c=t+'A';
			ss=ss+c;
			t++;
			v.pb(ss);
			v.pb(ss);
		}
		for(int i=1;i<n-k+1;i++){
			cin>>s;
			if(s=="YES"){
				for(int j=v.size();j<i+k;j++){
					string ss;
					char c=t/26+'A',c2=t%26+'a';
					ss=ss+c+c2;
					t++;
					v.pb(ss);
				}
			}
			else {
				v.pb(v[i]);
			}
		}
		while(v.size()<n)
		v.pb(v.back());
		cout<<v[0];
		for(int i=1;i<v.size();i++){
			cout<<" "<<v[i];
		}
		cout<<endl;
	}
}