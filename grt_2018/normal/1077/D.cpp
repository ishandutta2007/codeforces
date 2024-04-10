#include <iostream>
#include <cstdio>

using namespace std;

int n,k;
int T[2*100000+1];
int zlicz[2*100000+1];
int zakres;

bool check(int x)
{
    int s=0;
    for(int i=0; i<=zakres;i++)
        s+=zlicz[i]/x;
    if(s>=k)
        return 1;
    return 0;
}

int binSearch(int p, int k)
{
    int sr;
    while(p<=k)
    {
        sr=(p+k)/2;
        if(check(sr))
            p=sr+1;
        else
            k=sr-1;
    }
    return p-1;
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n;i++) {
        cin>>T[i];
        zlicz[T[i]]++;
        zakres=max(zakres,T[i]);
    }
    int y = binSearch(1,n);
    int ile=0;
    for(int i=0; i<=zakres;i++)
        while(ile<k&&zlicz[i]-y>=0)
        {
            zlicz[i]-=y;
            ile++;
            cout<<i<<" ";
        }
    return 0;
}