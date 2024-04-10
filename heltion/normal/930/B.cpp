#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 6000
string ss[maxn];
int cnt[26];
int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < 26; i += 1){
    	int ssn = 0;
    	for(int j = 0; j < s.size(); j += 1) if(s[j] == i + 'a')
    		ss[ssn ++] = s.substr(j, s.size() - j) + s.substr(0, j);
    	int pans = 0;
    	for(int j = 0; j < s.size(); j += 1){
    		memset(cnt, 0, sizeof cnt);
    		for(int k = 0; k < ssn; k += 1)
    			cnt[ss[k][j] - 'a'] += 1;
    		int ppans = 0;
    		for(int j = 0; j < 26; j += 1) if(cnt[j] == 1) ppans += 1;
    		pans = max(pans, ppans);
		}
		ans += pans;
    }
    cout << setprecision(15) << 1. * ans / s.size();
}