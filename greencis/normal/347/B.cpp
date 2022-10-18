#include <iostream>
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    int table[n];
    bool good[n];
    int good_numb=0;
    bool succ=false;
    bool isThereBad = false;

    for (int i =0;i<n;++i){
        table[i]=0;
        good[i]=false;
        cin>>table[i];
        if (table[i]==i){good[i]=true;++good_numb;}
        else isThereBad=true;
       // cout << "good_numb: "<<good_numb<<endl;
    }
    if (isThereBad)
        ++good_numb;

    for (int i = 0; i < n; ++i){
        if (!good[i]){
          //  cout << "i: "<<i<<endl;
          //  cout << "table[i]: "<<table[i]<<endl;
          //  cout << "table[table[i]]: "<<table[table[i]]<<endl;

            if (table[table[i]]==i){++good_numb;succ=true;break;}
//            for (int j=0;j<i;++j){
//                if (!good[j]&&table[i]==j&&table[j]==i){++good_numb;succ=true;break;}
//            }
        }
    }
    cout << good_numb;
    return 0;
}