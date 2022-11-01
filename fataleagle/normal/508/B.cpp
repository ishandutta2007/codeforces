#include <bits/stdc++.h>

using namespace std;

int N;
char S[100001];

int main()
{
    scanf("%s", S);
    N=strlen(S);
    int swapped=-1;
    for(int i=0; i<N; i++)
        if((S[i]-'0')%2==0 && !(i==0 && S[i]=='0') && S[i]<S[N-1])
        {
            swapped=i;
            break;
        }
    if(swapped==-1)
        for(int i=N-1; i>=0; i--)
            if((S[i]-'0')%2==0 && !(i==0 && S[i]=='0'))
            {
                swapped=i;
                break;
            }
    if(swapped==-1)
        printf("-1\n");
    else
    {
        swap(S[swapped], S[N-1]);
        puts(S);
    }
    return 0;
}