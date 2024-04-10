#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 100*1000+1;
string s,s2,s3;
int n,cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0; i<n;i++) {
        if(s[i]=='a') {
            cnt++;
        }
    }
    int len = (n-cnt)/2+cnt;
    for(int i=0; i<len;i++) {
        if(s[i]!='a') {
            s2+=s[i];
        }
    }
    for(int i=len;i<n;i++) {
        s3+=s[i];
    }
    if(s2!=s3) {
        cout<<":(";
    }
    else {
        for(int i=0; i<len;i++) {
            cout<<s[i];
        }
    }
}