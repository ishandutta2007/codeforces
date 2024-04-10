#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,a[52][52];
    long long c[52]={0},r[52]={0};
    vector <int> cnt(3,0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            r[i]+=a[i][j];
            c[j]+=a[i][j];
        }
    }
    cin >> cnt[0] >> cnt[1] >> cnt[2];
    sort(cnt.begin(),cnt.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            vector <long long> v;
            long long s=0;
            for(int t=0;t<=i;t++) s+=r[t];
            v.push_back(s);
            s=0;
            for(int t=i+1;t<=j;t++) s+=r[t];
            v.push_back(s);
            s=0;
            for(int t=j+1;t<n;t++) s+=r[t];
            v.push_back(s);
            sort(v.begin(),v.end());
            if (v[0]==cnt[0]&&v[1]==cnt[1]&&v[2]==cnt[2]) ans++;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m-1;j++)
        {
            vector <long long> v;
            long long s=0;
            for(int t=0;t<=i;t++) s+=c[t];
            v.push_back(s);
            s=0;
            for(int t=i+1;t<=j;t++) s+=c[t];
            v.push_back(s);
            s=0;
            for(int t=j+1;t<m;t++) s+=c[t];
            v.push_back(s);
            sort(v.begin(),v.end());
            if (v[0]==cnt[0]&&v[1]==cnt[1]&&v[2]==cnt[2]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}