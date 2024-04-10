#include<bits/stdc++.h>
#define maxn 5030

using namespace std;
double p;
int n,k,e,cnt[maxn][26],d;
char s[maxn];

int main()
{
    scanf("%s",s); n=strlen(s);
    for (char c='a';c<='z';c++)
    {
        memset(cnt,0,sizeof(cnt)); k=0;e=0;
        for (int i=0;i<n;i++)
        if (s[i]==c){
            k++;
            for (int j=1;j<n;j++) cnt[j][s[(i+j)%n]-'a']++;
        }
        for (int i=1;i<n;i++){
            d=0;
            for (int j=0;j<26;j++) d+=(cnt[i][j]==1);
            e=max(d,e);
        }
        p+=1.0*e/n;
    }
    printf("%.10f\n",p);
    return 0;
}