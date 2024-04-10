#include <bits/stdc++.h>
using namespace std;

// LEARN UNION FIND AND DISJOINT SET UNIONS

int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   int cells, y, lastgroup;
   cin >> cells;
   int perm[cells+1], fav[cells+1];
   int group[cells+1];
   memset(group, -1, sizeof(group));
   vector<vector<int*>> ptrgroup;
   /*
   group stores group num
   ptrgroup stores pointer to group
   */
   for (int i = 1; i <= cells; i++)
      cin >> perm[i];
   for (int i = 1; i <= cells; i++)
      cin >> fav[i];
   // end input
   // union thing
   for (int i = 1; i <= cells; i++) {
      // add i-fav and i+fav to group, if they exist
      if (group[i] == -1) {
         // add i to new group
         vector<int*> temp;
         group[i] = ptrgroup.size();
         temp.push_back(group+i); // pointer to i in group[]
         ptrgroup.push_back(temp); // add new group
      }
      y = i - fav[i];
      if (y > 0) {
         if (group[y] == -1) {
            // add y to group i
            group[y] = group[i];
            ptrgroup[group[i]].push_back(group+y);
         }
         else if (group[y] != group[i]){
            // add group y to group i (add vector y behind i)
            ptrgroup[group[i]].insert(ptrgroup[group[i]].end(), ptrgroup[group[y]].begin(), ptrgroup[group[y]].end());
            // change links in group[]
            lastgroup = group[y];
            for (int j = 0; j < ptrgroup[group[y]].size(); j++) {
               *ptrgroup[group[y]][j] = group[i];
            }
            // erase former group y
            ptrgroup.erase(ptrgroup.begin() + lastgroup);
            // shift links in group[]
            for (int j = lastgroup; j < ptrgroup.size(); j++) {
               for (int k = 0; k < ptrgroup[j].size(); k++) {
                  (*ptrgroup[j][k])--;
               }
            }
         }
      }
      y = i + fav[i];
      if (y <= cells) {
         if (group[y] == -1) {
            // add y to group i
            group[y] = group[i];
            ptrgroup[group[i]].push_back(group+y);
         }
         else if (group[y] != group[i]){
            // add group y to group i (add vector y behind i)
            ptrgroup[group[i]].insert(ptrgroup[group[i]].end(), ptrgroup[group[y]].begin(), ptrgroup[group[y]].end());
            // change links in group[]
            lastgroup = group[y];
            for (int j = 0; j < ptrgroup[group[y]].size(); j++) {
               *ptrgroup[group[y]][j] = group[i];
            }
            // erase former group y
            ptrgroup.erase(ptrgroup.begin() + lastgroup);
            // shift links in group[]
            for (int j = lastgroup; j < ptrgroup.size(); j++) {
               for (int k = 0; k < ptrgroup[j].size(); k++) {
                  (*ptrgroup[j][k])--;
               }
            }
         }
      }
   }
   for (auto v : ptrgroup) {
      vector<int> a, b;
      for (int i = 0; i < v.size(); i++) { // iterate through pointers
         a.push_back(v[i] - group);
         b.push_back(perm[v[i] - group]); // get values
      }
      // sort temp and v
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      for (int i = 0; i < a.size(); i++) {
         if (a[i] != b[i]) {
            cout << "NO" << endl;
            return 0;
         }
      }
   }
   cout << "YES" << endl;
   return 0;
}