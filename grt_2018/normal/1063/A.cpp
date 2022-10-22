#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int n;
int cnt[26];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) {
        cnt[s[i]-'a']++;
    }
    for(int i=0; i<26;i++) {
        while(cnt[i]--) {
            cout<<(char)(i+'a');
        }
    }
}