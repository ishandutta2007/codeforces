#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,a,b;
    cin >> n >> k;
    vector <pair <int,int> > v;
    for(int i=0;i<n;++i) {
        cin >> a >> b;
        v.push_back(make_pair(-a,b));
    }
    sort(v.begin(),v.end()); --k;
    int ans=1,pos=k-1;
    while(pos>=0&&v[pos]==v[k]) --pos,ans++;
    pos=k+1;
    while(pos<n&&v[pos]==v[k]) ++pos,ans++;
    cout << ans << endl;
    return 0;
}