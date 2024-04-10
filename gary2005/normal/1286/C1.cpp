/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<string ,int > M;
bool cmp(string A,string B){
	return A.length()<B.length();
}
vector<int> v(26,26);
int main(){
	fastio;
	int n;
	cin>>n;
	if(n==1){
		char c;
		cout<<"? 1 1\n";ff;
		cin>>c;
		cout<<"! "<<c<<endl;
		return 0;
	}
	if(n==2){
		string c;
		cout<<"? 1 1\n";ff;
		cin>>c;
		string res="";
		res+=c;
		cout<<"? 2 2\n";ff;
		cin>>c;
		res+=c;
		cout<<"! "<<res<<endl;
		return 0;
	}
	if(n==3){
		string c;
		cout<<"? 1 1\n";ff;
		cin>>c;
		string res="";
		res+=c;
		cout<<"? 2 2\n";ff;
		cin>>c;
		res+=c;
		cout<<"? 3 3\n";ff;
		cin>>c;
		res+=c;
		cout<<"! "<<res<<endl;
		return 0;
	}
	cout<<"? 1 "<<n-1<<endl;ff;
	rb(i,1,((n-1)*(n))>>1){
		string c;
		cin>>c;
		sort(ALL(c));
		M[c]++;
	}
	cout<<"? 2 "<<n-1<<endl;ff;
	rb(i,1,((n-1)*(n-2))>>1){
		string c;
		cin>>c;
		sort(ALL(c));
		M[c]--;
		if(M[c]==0) M.erase(c);
	}
	vector<string> all;
	for(map<string ,int> :: IT ite=M.begin();ite!=M.end();ite++){
		all.PB(ite->FIR);
	}
	sort(ALL(all),cmp);
	rep(i,26) v[i]=0;
	string res="";
	for(auto it:all){
		vector<int> tmp;
		tmp=v;
		char c;
		rep(j,it.length()){
			if(v[it[j]-'a'])
			{
				v[it[j]-'a']--;
			}
			else{
				c=it[j];
				break;
			}
		}
		tmp[c-'a']++;
		res+=c;
		v=tmp;
	}
	string c;
	cout<<"? "<<n<<" "<<n<<endl;ff;
	cin>>c;
	res+=c;
	cout<<"! "<<res<<endl;
	return 0;
}