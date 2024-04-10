#include <bits/stdc++.h>
 
using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;
 
int n;
bool expr[100001];
int br[2][100002]; /* 0: (, 1: ) */
 
/* impossible */
void end() {
  cout << "NO" << endl;
  exit(0);
}
 
/* print the output, based on how many brackets are between each thing */
void print() {
  cout << "YES" << endl;
  f0r(i, n) {
    if (i) cout << "->";
    f0r(j, br[0][i]) cout << "(";
    cout << expr[i];
    f0r(j, br[1][i]) cout << ")";
  }
  exit(0);
}
 
int main() {
  cin >> n;
  f0r(i, n) cin >> expr[i];
  
  /* special case, can't do anything */
  if (n == 1) (expr[0]) ? end() : print();
  
  /* initialize brackets to 0 */
  memset(br, 0, sizeof(br));
  
  /* last thing is 1, nothing we can do */
  if (expr[n - 1]) end();
  
  /* now the last thing is 0, and we want everything before it to evaluate to 1 */
  
  /* if the second-last thing is 1, then it's already good */
  if (expr[n - 2]) print();
  
  /* now we have something of the form x -> 0 -> 0 */
  /* and thus want x to evaluate to 0, or (x -> 0) to evaluate to 1 */
  
  /* find a 0 in x, if there are multiple, find the leftmost 0 */
  int l = -1;
  f0r(k, n - 2) if (!expr[k] && l == -1) l = k;
  
  /* if everything in x is a 1, then the whole thing will be 1 */
  /* so we are forced to have 1 -> 0 -> 0 which evaluates to 1, and it's impossible to fix */
  if (l == -1) end();
  
  /* now we have something of the form x -> (y) -> 0 */
  /* where x is of the form 1 -> 1 -> ... -> 1 -> 1 -> 0 (possibly no 1's) */
  /* so x will always evaluate to 0 */
  /* this is true because we found the leftmost 0 for x */
  
  /* and y is anything, doesn't matter, because 0 -> 0 = 1 and 0 -> 1 = 1 */
  /* so we have 1 -> 0 = 0, which works! */
  
  br[0][l + 1]++;
  br[1][n - 2]++;
  print();
}