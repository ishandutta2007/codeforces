#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

char str[100001];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int k,n=strlen(str);
    scanf("%d",&k);
    if (1LL*n*(n+1)/2<k)
    {
        printf("No such line.\n");
        return 0;
    }
    ll sum[30]={0},cnt[30]={0};
    for(int i=0;i<n;i++)
        sum[str[i]-'a']+=n-1-i+1,cnt[str[i]-'a']++;
    char let='a';
    for(int i=0;i<26;i++)
    {
        if (k<=sum[i]) break;
        k-=sum[i]; let++;
    }
    k-=cnt[let-'a'];
    vector <int> pos,pos1;
    for(int i=0;i<n;i++)
        if (str[i]==let) pos.push_back(i);
    printf("%c",let);
    while(k>0)
    {
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<pos.size();i++)
            if (pos[i]!=n-1) sum[str[pos[i]+1]-'a']+=n-1-pos[i],cnt[str[pos[i]+1]-'a']++;
        let='a';
        for(int i=0;i<26;i++)
        {
            if (k<=sum[i]) break;
            k-=sum[i]; let++;
        }
        k-=cnt[let-'a'];
        printf("%c",let);
        pos1.clear();
        for(int i=0;i<pos.size();i++)
            if (str[pos[i]+1]==let) pos1.push_back(pos[i]+1);
        pos=pos1;
    }
    printf("\n");
    return 0;
}