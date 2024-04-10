#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100005];
int t,n,cnt[26];
int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=0;i<26;++i)
            cnt[i]=0;
        for(int i=1;i<=n;++i)
            ++cnt[s[i]-'a'];
        bool flag=0;
        int tot=0;
        for(int i=0;i<26;++i)
        {
            if(cnt[i])
                ++tot;
            if(cnt[i]==1)
            {
                putchar(i+'a');
                --cnt[i];
                for(int j=0;j<26;++j)
                    for(int k=1;k<=cnt[j];++k)
                        putchar(j+'a');
                puts("");
                flag=1;
                break;
            }
            if(cnt[i]==n)
            {
                for(int j=1;j<=n;++j)
                    putchar(i+'a');
                puts("");
                flag=1;
                break;
            }
        }
        if(flag)
            continue;
        for(int i=0;i<26;++i)
            if(cnt[i])
            {
                if(2*(cnt[i]-1)<=n)
                {
                    putchar(i+'a');
                    --cnt[i];
                    int pos=i+1;
                    while(cnt[i]>1)
                    {
                        putchar(i+'a');
                        --cnt[i];
                        while(pos<26&&!cnt[pos])
                            ++pos;
                        putchar(pos+'a');
                        --cnt[pos];
                    }
                    for(int j=i;j<26;++j)
                        for(int k=1;k<=cnt[j];++k)
                            putchar(j+'a');
                }
                else
                {
                    putchar(i+'a');
                    --cnt[i];
                    if(tot==2)
                    {
                        for(int j=i+1;j<26;++j)
                            if(cnt[j])
                            {
                                for(int k=1;k<=cnt[j];++k)
                                    putchar(j+'a');
                                for(int k=1;k<=cnt[i];++k)
                                    putchar(i+'a');
                            }
                    }
                    else
                    {
                        for(int j=i+1;j<26;++j)
                            if(cnt[j])
                            {
                                putchar(j+'a');
                                --cnt[j];
                                for(int k=1;k<=cnt[i];++k)
                                    putchar(i+'a');
                                for(int k=j+1;k<26;++k)
                                    if(cnt[k])
                                    {
                                        putchar(k+'a');
                                        --cnt[k];
                                        break;
                                    }
                                break;
                            }
                        for(int j=i+1;j<26;++j)
                            for(int k=1;k<=cnt[j];++k)
                                putchar(j+'a');
                    }
                }
                puts("");
                break;
            }
    }
    return 0;
}