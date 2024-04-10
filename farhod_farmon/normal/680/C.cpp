#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int cnt = 0, curx = 1;

int main()
{
    int h = 0;
    for(int i = 2; i <= 50; i++){
        int col = 0;
        for(int j = 2; j < i; j++)
            if(i % j == 0)
                col++;
        if(!col){
            cout << i << endl;
            string s;
            cin >> s;
            if(s == "yes"){
                cnt++;
                if(i * i > 100)
                    continue;
                cout << i * i << endl;
                cin >> s;
                if(s == "yes")
                    cnt++;
                h++;
            }
            h++;
        }
    }
    if(cnt <= 1)
        cout << "prime" << endl;
    else
        cout << "composite" << endl;
    fflush(stdout);
}