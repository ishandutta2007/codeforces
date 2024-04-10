#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            if(s.at(j)=='.') a[i][j]=0;
            else if(s.at(j)=='X') a[i][j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(a[i][j]==1&&a[i+1][j+1]==1&&a[i+1][j-1]==1&&a[i-1][j+1]==1&&a[i-1][j-1]==1) ans++;
        }
    }
    cout<<ans;
    return 0;
}