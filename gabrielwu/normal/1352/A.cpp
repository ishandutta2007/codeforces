#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int x=0; x<t; x++){
    string n;
    cin >> n;
    vector<char> a;
    for (int count=0;count<n.length();count++){
      a.push_back(n.at(count));
    }
    int counter=0;
    for (int count=0;count<n.length();count++){
      if (a[count]!='0'){
        counter++;
      }
    }
    cout<<counter<<endl;
    for (int count=0;count<a.size();count++){
      if (a[count]!='0'){
        cout<<a[count];
        for (int count2=0;count2<a.size()-count-1;count2++){
          cout<<'0';
        }
        cout<<' ';
      }
    }
    cout<<endl;
  }

}