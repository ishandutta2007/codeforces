#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2*100001;

int n;
int T[MAXN];
int S[MAXN],r=0;

int main()
{
    cin>>n;
    for(int i=0; i<n;i++)
        cin>>T[i];
    sort(T,T+n);
    int ile=1;
    for(int i=1; i<n;i++)
    {
        if(T[i]==T[i-1])
            ile++;
        else
        {
            S[r]=ile;
            ile=1;
            r++;
        }
    }
    S[r]=ile;
    r++;
    sort(S,S+r);
    int w=0;
    int pom2;
    for(int i=1; i<=n;i++)
    {
        int c=i;
        int pom=r-1;
        pom2=0;
        while(c>0)
        {
            if(c>S[pom]) c=0;
            else w=max(w,pom2+c);
            if(c%2==1||pom==0) c=0;
            else
            {
                pom2+=c;
                c/=2;
                pom--;
            }

        }
    }
    cout<<w;
    return 0;
}