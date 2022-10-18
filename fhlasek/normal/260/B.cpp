/* Written by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char ll[111111], *l;
int cnt[111111];

int main(int argc, char *argv[]){
  int best = 0, bday = 0, bmonth = 0, byear = 0;
  scanf("%s", ll);
  int N = strlen(ll);
  l = ll;
  REP(i, N-9){
    if(l[0] != '-' && l[1] != '-' && l[2] == '-' && l[3] != '-' && l[4] != '-' && l[5] == '-' && l[6] != '-' && l[7] != '-' && l[8] != '-' && l[9] != '-'){
      int day = 10*(l[0] - '0') + l[1] - '0';
      int month = 10*(l[3] - '0') + l[4] - '0';
      int year = 1000*(l[6] - '0') + 100*(l[7] - '0') + 10*(l[8] - '0') + l[9] - '0';
      if(year > 2015 || year < 2013 || month < 1 || month > 12 || day < 1 || day > days[month-1]){ l++; continue; }
      if(best < ++cnt[10000 * (year - 2013) + 100 * day + month]){
        best = cnt[10000 * (year - 2013) + 100 * day + month];
        bday = day;
        bmonth = month;
        byear = year;
      }
    };
    l++;
  }
  printf("%02d-%02d-%d\n", bday, bmonth, byear);
  return 0;
}