#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define ll long long

using namespace std;

int a[1002],b[1002],c[1002],d[1002];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    char A,B,C,D;
    scanf("%d",&n);
    cin >> A >> B >> C >> D;
    a[0]=A-'0';
    b[0]=B-'0';
    c[0]=C-'0';
    d[0]=D-'0';
    for(int i=1;i<n;i++)
    {
        cin >> A >> B;
        cin >> A >> B >> C >> D;
        a[i]=A-'0';
        b[i]=B-'0';
        c[i]=C-'0';
        d[i]=D-'0';
    }
    bool used[1003]={0};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if (!used[i])
        {
            used[i]=true;
            ans++;
            for(int j=i+1;j<n;j++)
            {
                if (a[i]==a[j]&&b[i]==b[j]&&c[i]==c[j]&&d[i]==d[j]||
                    a[i]==c[j]&&b[i]==a[j]&&c[i]==d[j]&&d[i]==b[j]||
                    a[i]==d[j]&&b[i]==c[j]&&c[i]==b[j]&&d[i]==a[j]||
                    a[i]==b[j]&&b[i]==d[j]&&c[i]==a[j]&&d[i]==c[j]) used[j]=true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}