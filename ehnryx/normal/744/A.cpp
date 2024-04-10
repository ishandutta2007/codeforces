#include <bits/stdc++.h>
using namespace std;

/*
10 10 3
1 2 3
3 4
5 6
7 8
9 10
5 3
6 3
4 6
*/

int main() {
   ios::sync_with_stdio(0);
   int n, m, k, x, y;
   cin >> n >> m >> k;
   int group[n+1];
   for (int i = 0; i <= n; i++) {
      group[i] = -1;
   }
   int govt[k], govtsize[k];
   int nsum, maxpos, lastgroup;
   vector<vector<int*> > ptrgroup;
   for (int i = 0; i < k; i++)
      cin >> govt[i];
   for (int i = 0; i < m; i++) {
      //cout << "ptrgroup: " << ptrgroup.size() << endl;;
      /*for (int j = 0; j <= n; j++) {
         cout << j << ":" << group[j] << " ";
      } cout << endl; */
      cin >> x >> y;
      //cout << "x :" << group[x] << " y :" << group[y] << endl;
      if (group[x] == -1) {
         //cout << "add " << x << " to new group\n";
         // add to new group
         vector<int*> temp;
         group[x] = ptrgroup.size();
         temp.push_back(group+x); // pointer to x in group[]
         ptrgroup.push_back(temp); // add new group
      }
      if (group[y] == -1) {
         //cout << "add " << y << " to group " << x << endl;
         // add to group containing x
         group[y] = group[x];
         ptrgroup[group[x]].push_back(group+y);
      }
      else if (group[y] != group[x]){
         //cout << "add group " << y << " to group " << x << endl;
         // add group y to group x
         // add vector y behind x
         ptrgroup[group[x]].insert(ptrgroup[group[x]].end(), ptrgroup[group[y]].begin(), ptrgroup[group[y]].end());
         // change links
         lastgroup = group[y];
         for (int j = 0; j < ptrgroup[group[y]].size(); j++) {
            *ptrgroup[group[y]][j] = group[x];
         }
         // erase
         ptrgroup.erase(ptrgroup.begin() + lastgroup);
         for (int j = lastgroup; j < ptrgroup.size(); j++) {
            for (int k = 0; k < ptrgroup[j].size(); k++) {
               (*ptrgroup[j][k])--;
            }
         }
      }
   }
   //cout << "after grouping" << endl;
   maxpos = 0; nsum = 0;
   for (int i = 0; i < k; i++) {
      if (group[govt[i]] == -1) {
         govtsize[i] = 1;
      }
      else {
         govtsize[i] = ptrgroup[group[govt[i]]].size();
         //cout << i << ": " << govtsize[i] << endl;
         if (govtsize[i] > govtsize[maxpos])
            maxpos = i;
      }
      nsum += govtsize[i];
   }
   //cout << "before cleanup" << endl;
   // add everything else to govtsize[maxpos]
   //cout << "maxpos: " << maxpos << endl;
   govtsize[maxpos] += n - nsum;
   // calculate edges
   int total_edges = 0;
   for (int i = 0; i < k; i++) {
      total_edges += (govtsize[i]*(govtsize[i]-1))/2;
      //cout << "te: " << total_edges << endl;
   }
   cout << total_edges - m << endl;
   //cout << "end" << endl;
   return 0;
}