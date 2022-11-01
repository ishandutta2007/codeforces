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

char buf[50000];

int main()
{
    gets(buf);
    int n = strlen(buf);
    string now = "";
    bool space = false;
    REP(i,n)
    {
        if (buf[i]>='a'&&buf[i]<='z') now+=buf[i];
        else if (buf[i]==' ')
        {
            if (now==" ") continue;
            cout<<now;
            now=" ";
            space = true;
            continue;
        }
        else
        {
            if (space && now==" ")
            {
                cout<<buf[i];
                now = " ";
                space = false;
                continue;
            }
            cout<<now<<buf[i];
            now=" ";
        }
    }
    if (now!=" ") cout<<now;
    cout<<endl;
	return 0;
}