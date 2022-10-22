#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 300*1000+10;
int n;
string s;
bool ans[MAXN];
int l,r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) {
        if(s[i]=='(') l++;
        if(s[i]==')') r++;
    }
    for(int i=0; i<n;i++) {
        if(s[i]=='?') {
            if(l<n/2) {
                l++;
                ans[i]=1;
            }
            else {
                ans[i]=0;
                r++;
            }
        }
        else if(s[i]=='(') ans[i]=1;
        else ans[i]=0;
    }
    if(l!=r) {
        cout<<":(";
        return 0;
    }
    int o=0;
    for(int i=0; i<n;i++) {
        if(ans[i]) o++;
        else o--;
        if(o<0||(o==0&&i<n-1)) {
            cout<<":(";
            return 0;
        }
    }
    if(o!=0) {
        cout<<":(";
        return 0;
    }
    for(int i=0; i<n;i++) {
        if(ans[i]) cout<<"(";
        else cout<<")";
    }
}