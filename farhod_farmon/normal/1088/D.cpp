#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int my_a = 321;
int my_b = 213;

int get(int x, int y)
{

        //if((my_a ^ x) > (my_b ^ y)){
        //        return 1;
        //}
        //if((my_a ^ x) < (my_b ^ y)){
        //        return -1;
        //}
        //return 0;

        int g;
        cout << "? " << x << " " << y << endl;
        cin >> g;
        return g;
}

int fat(int x, int y)
{
        if(x > y){
                return 1;
        }
        if(x < y){
                return -1;
        }
        return 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int a = 0, b = 0;
        int now = get(0, 0);
        //for(int i = 8; i >= 0; i--){
        //        cout << ((my_a >> i) & 1) << " " << ((my_b >> i) & 1) << endl;
        //}
        //cout << endl;
        for(int h = 29; h >= 0; h--){
                //now = get(a, b);
                int tp = get(a | (1 << h), b | (1 << h));
                if(tp != now){
                        tp = 1;
                }
                else{
                        tp = 0;
                }
                int x = get(a | (1 << h), b);
                int fx = 0, fy = 0;
                //cout << now << " " << x << " " << tp << endl;
                for(int i = 0; i < 2; i++){
                        for(int j = 0; j < 2; j++){
                                if(fat(i, j) != now && fat(i, j) != 0){
                                        continue;
                                }
                                if(abs(fat(i, j)) != tp){
                                        continue;
                                }
                                //cout << i << " " << j << endl;
                                if((fat(i ^ 1, j) == x || !fat(i ^ 1, j))){
                                        fx = i;
                                        fy = j;
                                }
                        }
                }
                //cout << fx << " " << fy << endl;
                //return 0;
                a |= fx << h;
                b |= fy << h;
                if(fat(fx, fy)){
                        now = x;
                }
        }
        cout << "! " << a << " " << b << endl;
}