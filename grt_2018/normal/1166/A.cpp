#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>ii;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

int n;
char s[100];
int cnt[26];
LL ans;

int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%s",s);
        cnt[s[0]-'a']++;
    }
    for(int i=0; i<26;i++) {
        int f = cnt[i]/2;
        int se = cnt[i]-f;
        ans+=(LL)f*(f-1)/2+(LL)se*(se-1)/2;
    }
    printf("%lld",ans);
}