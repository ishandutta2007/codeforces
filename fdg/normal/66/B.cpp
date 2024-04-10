#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,v[1001]={0},ret=1;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int i=0;i<n;i++)
    {
        int l=i,r=i;
        while(l>0&&v[l-1]<=v[l]) l--;
        while(r<n-1&&v[r+1]<=v[r]) r++;
        if (r-l+1>ret) ret=r-l+1;
    }
    cout << ret << endl;
    return 0;
}