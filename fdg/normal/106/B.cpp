#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a[101],b[101],c[101],d[101];
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        bool ok=true;
        for(int j=0;j<n;j++)
            if (a[i]<a[j]&&b[i]<b[j]&&c[i]<c[j]) ok=false;
        if (ok&&(ans==-1||d[ans]>d[i])) ans=i;
    }
    cout << ans+1 << endl;
    return 0;
}