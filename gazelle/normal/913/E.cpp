#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<string> ans1(256,"");
	vector<string> ans2(256,"");
	ans1[15]="x";
	ans1[51]="y";
	ans1[85]="z";
	ans2[15]="x";
	ans2[51]="y";
	ans2[85]="z";
	vector<pair<string,P>> vec;
	vec.pb(make_pair("x",P(15,0)));
	vec.pb(make_pair("y",P(51,0)));
	vec.pb(make_pair("z",P(85,0)));
	vec.pb(make_pair("x",P(15,1)));
	vec.pb(make_pair("y",P(51,1)));
	vec.pb(make_pair("z",P(85,1)));
	vector<bool> used1(256,false);
	vector<bool> used2(256,false);
	used1[0]=true;
	used1[15]=true;
	used1[51]=true;
	used1[85]=true;
	used2[0]=true;
	used2[15]=true;
	used2[51]=true;
	used2[85]=true;
	while(1) {
		bool update=false;
		REP(i,(ll)vec.size()) {
			string buf1="";
			if((ll)vec[i].first.size()>1) buf1="("+vec[i].first+")";
			else buf1=vec[i].first;
			buf1="!"+buf1;
			if(ans1[vec[i].second.first^255]==""||(ll)ans1[vec[i].second.first^255].size()>(ll)buf1.size()||((ans1[vec[i].second.first^255].size()==(ll)buf1.size())&&(ans1[vec[i].second.first^255]>buf1))) {
				ans1[vec[i].second.first^255]=buf1;
			}
			if(ans2[vec[i].second.first^255]==""||(ll)ans2[vec[i].second.first^255].size()>(ll)buf1.size()||((ans2[vec[i].second.first^255].size()==(ll)buf1.size())&&(ans2[vec[i].second.first^255]>buf1))) {
				ans2[vec[i].second.first^255]=buf1;
			}
			FOR(j,i+1,(ll)vec.size()) {
				string& to1=ans1[vec[i].second.first&vec[j].second.first];
				string& to2=ans2[vec[i].second.first&vec[j].second.first];
				string& to3=ans2[vec[i].second.first|vec[j].second.first];
				string str1="";
				string str2="";
				if((ll)vec[i].second.second==0) {
					if((ll)vec[j].second.second==0) {
						str1=min(vec[i].first+"&"+vec[j].first,vec[j].first+"&"+vec[i].first);
						str2=min(vec[i].first+"|"+vec[j].first,vec[j].first+"|"+vec[i].first);
					} else {
						str1=min(vec[i].first+"&("+vec[j].first+")","("+vec[j].first+")&"+vec[i].first);
						str2=min(vec[i].first+"|"+vec[j].first,vec[j].first+"|"+vec[i].first);
					}
				} else {
					if((ll)vec[j].second.second==0) {
						str1=min(vec[j].first+"&("+vec[i].first+")","("+vec[i].first+")&"+vec[j].first);
						str2=min(vec[i].first+"|"+vec[j].first,vec[j].first+"|"+vec[i].first);
					} else {
						str1=min("("+vec[i].first+")&("+vec[j].first+")","("+vec[j].first+")&("+vec[i].first+")");
						str2=min(vec[i].first+"|"+vec[j].first,vec[j].first+"|"+vec[i].first);
					}
				}
				if(to1==""||(ll)to1.size()>(ll)str1.size()||((ll)(to1.size())==(ll)str1.size()&&to1>str1)) {
					to1=str1;
				}
				if(to2==""||(ll)to2.size()>(ll)str1.size()||((ll)(to2.size())==(ll)str1.size()&&to2>str1)) {
					to2=str1;
				}
				if(to3==""||(ll)to3.size()>(ll)str2.size()||((ll)(to3.size())==str2.size()&&to3>str2)) {
					to3=str2;
				}
			}
		}
		ll mini=INF*INF;
		REP(i,256) {
			if(ans1[i]!=""&&!used1[i]&&(ll)ans1[i].size()<mini) {
				mini=(ll)ans1[i].size();
			}
		}
		REP(i,256) {
			if(ans1[i]!=""&&!used1[i]&&(ll)ans1[i].size()==mini) {
				used1[i]=true;
				vec.pb(make_pair(ans1[i],P(i,0ll)));
				update=true;
			}
		}
		REP(i,256) {
			if(ans2[i]!=""&&!used2[i]&&(ll)ans2[i].size()<mini) {
				mini=(ll)ans2[i].size();
			}
		}
		REP(i,256) {
			if(ans2[i]!=""&&!used2[i]&&(ll)ans2[i].size()==mini) {
				used2[i]=true;
				vec.pb(make_pair(ans2[i],P(i,1ll)));
				update=true;
			}
		}
		if(!update) break;
	}
	REP(i,n) {
		string tr;
		cin>>tr;
		ll tmp=0;
		ll buf=1;
		REP(j,8) {
			if(tr[7-j]=='1') tmp+=buf;
			buf*=2;
		}
		if(ans1[tmp]!="") {
			if(ans2[tmp]!="") {
				if((ll)ans1[tmp].size()<(ll)ans2[tmp].size()) {
					cout<<ans1[tmp]<<endl;
				} else {
					cout<<ans2[tmp]<<endl;
				}
			} else {
				cout<<ans1[tmp]<<endl;
			}
		} else {
			if(ans2[tmp]!="") {
				cout<<ans2[tmp]<<endl;
			} else {
				cout<<ans1[tmp]<<endl;
			}
		}
	}
}