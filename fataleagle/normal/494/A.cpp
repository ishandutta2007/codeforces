#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[100001];
char T[300001];

int main()
{
    scanf("%s", S);
    N=strlen(S);
    int need=0, hashtag=0;
    for(int i=0; i<N; i++)
        if(S[i]=='(')
            need++;
        else if(S[i]==')')
            need--;
        else
            hashtag++;
    if(need<hashtag)
    {
        printf("-1\n");
        return 0;
    }
    int ohashtag=hashtag, oneed=need;
    for(int i=0; i<N; i++)
        if(S[i]=='#')
        {
            hashtag--;
            if(hashtag==0)
            {
                for(int j=0; j<need; j++)
                    T[M++]=')';
            }
            else
            {
                T[M++]=')';
                need--;
            }
        }
        else
            T[M++]=S[i];
    int presum=0;
    for(int i=0; i<M; i++)
    {
        if(T[i]=='(')
            presum++;
        else if(T[i]==')')
        {
            if(presum==0)
            {
                printf("-1\n");
                return 0;
            }
            presum--;
        }
    }
    if(presum==0)
    {
        for(int i=1; i<ohashtag; i++)
            printf("1\n");
        printf("%d\n", oneed-ohashtag+1);
    }
    else
        printf("-1\n");
    return 0;
}