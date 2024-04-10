#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

char s[100005];
int n;
vector<pair<char, string> > q;

long long term[256], factor[256];
bool read=0, write=1;

int main(){
	scanf("%s", s);
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		char d;
		string t;
		cin >> d >> t;
		string t2;
		for(int j=2; j < t.size(); ++j)
			t2.push_back(t[j]);
		q.push_back(make_pair(d, t2));
	}
	for(int i=0; i < 10; ++i){
		term[i+'0']=i;
		factor[i+'0']=10;
	}
	for(int i=q.size()-1; i >= 0; --i){
		long long termN=0, factorN=1;
		char d=q[i].first;
		string t = q[i].second;
		for(int j=t.size()-1; j >= 0; --j){
			termN = (termN + factorN*term[t[j]]) % MOD;
			factorN = (factorN * factor[t[j]]) % MOD;
		}
		term[d] = termN;
		factor[d] = factorN;
	}
	long long ans=0;
	long long f=1;
	for(int i=strlen(s)-1; i >= 0; --i){
		ans = (ans + f*term[s[i]]) % MOD;
		f = (f * factor[s[i]]) % MOD;
	}
	printf("%I64d\n", ans);
}