#include <bits/stdc++.h>
using namespace std;

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

int main()
{
    fast_io();
    int n;
    cin >> n;

    if(n%3 == 0){
        cout << (n/3)*2 << " " ;
    }
    else {
        cout << (n/3)*2 + 1 << " ";
    }

}