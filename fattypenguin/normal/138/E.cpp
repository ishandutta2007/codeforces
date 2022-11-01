#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

vector<int> ch[26];
vector< pair<int,int> > con[26];
char s[1000007];
int sat[1000007];
int before[1000007];
int k,L,R;

int main()
{
    gets(s);
    int n = strlen(s);
    REP(i,n)
    {
        before[i] = ch[s[i]-'a'].size();
        ch[s[i]-'a'].PB(i);
    }
    cin>>k>>L>>R;
    char t[10];
    REP(i,k)
    {
        int a,b;
        cin>>t>>a>>b;
        con[t[0] -'a'].PB(MP(a,b));
    }
    int now = 0;
    long long answer = 0;
    CLEAR(sat);
  //  cout<<"here\n";
    REP(i,n)
    {
    //    cout << "here\n";

        REP(j,26)
            TR(it,con[j])
            {
                if (j==s[i]-'a')
                {
                    if (it->first <= 1 && it->second >= 1)
                        ++sat[i];
                }
                else
                {
                    if (it->first==0)
                        ++sat[i];
                }
            }
          //  cout<<"here\n";
        if (sat[i]>=L&&sat[i]<=R)
            ++now;
        TR(it,con[s[i]-'a'])
        {
            if (before[i] >= it->second)
            {
      //          cout<<"here\n";
                for (int j = before[i]-it->second-1<0 ? 0 : ch[s[i]-'a'][before[i]-it->second-1]+1;j <= min(i-1,ch[s[i]-'a'][before[i]-it->second]);++j)
                {
                //    cout<<j<<endl;
                    if (sat[j]>=L&&sat[j]<=R)
                        --now;
                    --sat[j];
                    if (sat[j]>=L&&sat[j]<=R)
                        ++now;
                }
            }
        }
        TR(it,con[s[i]-'a'])
        {
            if (before[i]+1 >= it->first)
            {
                int bound = before[i]-it->first+1 < ch[s[i]-'a'].size() ? ch[s[i]-'a'][before[i]-it->first+1] : i;
                for (int j = before[i]-it->first<0 ? 0 : ch[s[i]-'a'][before[i]-it->first]+1;j <= min(i-1,bound);++j)
                {
                    if (sat[j]>=L&&sat[j]<=R)
                        --now;
                    ++sat[j];
                    if (sat[j]>=L&&sat[j]<=R)
                        ++now;
                }
            }
        }
    //    cout<<now<<endl;
        answer += now;
    }
    cout << answer << endl;
    return 0;
}