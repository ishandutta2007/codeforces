#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define y0 qgoiqoeinfoiqwef
#define y1 vmpoqmeppjofaqoi
#define yn qoigmnioqonfopiq
#define ff first
#define ss second
bool b[26]={1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0};
string s;
int main()
{
    bool F=1;
    cin>>s;
    for(int i=0;i<=s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1]||!b[s[i]-'A']){F=0;break;}
    }
    if(F==1)cout<<"YES";else cout<<"NO";
 // system("pause");
    return 0;
}