#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=1e5+100;
typedef long long ll;
ll cnt[26],x,l,r;
char s[maxn];
int n;
int main(){
    cin >> n >> x >> s;
    x-=1<<(s[n-1]-'a');
    x+=1<<(s[n-2]-'a');
    for (int i=0;i<n-2;i++) cnt[s[i]-'a']++;
    l=x; r=x;
    for (int i=0;i<26;i++){
        if ((l+cnt[i])%2) l++;
        if ((r+cnt[i])%2) r--;
        if (l>r){puts("No");return 0;}
        l=(l-cnt[i])/2; r=(r+cnt[i])/2;
        if (l>r){puts("No");return 0;}
    }
    if (l<=0&&r>=0) puts("Yes"); else puts("No");
    return 0;
}