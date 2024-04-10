#include<bits/stdc++.h>
#define maxn 150205

using namespace std;
char s[maxn];
int cnt[26],n;

int main()
{
    scanf("%s",s);
    n=strlen(s);
    for (int i=0;i<n;i++) cnt[s[i]-'a']++;
    sort(cnt,cnt+26);
    if (cnt[21]) puts("No");
    else if (cnt[22]) puts("Yes");
    else if (cnt[23]){
        if (cnt[25]>1) puts("Yes"); else puts("No");
    }
    else if (cnt[24]){
        if (cnt[24]>1) puts("Yes"); else puts("No");
    }
    else puts("No");
    return 0;
}