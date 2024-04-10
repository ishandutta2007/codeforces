#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        cout << "SCAN " << 1 << " " << 1 << endl;
        fflush(stdout);
        int sum_1;
        cin >> sum_1; //u :=  x_1 + y_1 + x_2 + y_2 - 4
        cout << "SCAN " << 1 << " " << m << endl;
        fflush(stdout);
        int sum_2;
        cin >> sum_2; //sum_2 := x_1 + x_2 - y_1 - y_2 + 2*m - 2
        int sum_of_x = (sum_1 + sum_2 + 6 - 2*m)/2;
        int sum_of_y = sum_1 + 4 - sum_of_x;
        cout << "SCAN " << sum_of_x/2 << " " << 1 << endl;
        fflush(stdout);
        int x1,x2;
        int sum_3;
        cin >> sum_3; //sum_3
        sum_3 = sum_3 + 2 - sum_of_y;
        x2 = (sum_3 + sum_of_x) / 2;
        x1 = sum_of_x - x2;
        cout << "SCAN " << 1 << " " << sum_of_y/2 << endl;
        fflush(stdout);
        int y1,y2;
        int sum_4;
        cin >> sum_4;
        sum_4 = sum_4 + 2 - sum_of_x;
        y2 = (sum_4 + sum_of_y) / 2;
        y1 = sum_of_y - y2;
        //Check (x1,y1) vs (x2,y2)
        cout << "DIG " << x1 << " " << y1 << endl;
        fflush(stdout);
        int status;
        cin >> status;
        if (status == 1){
            cout << "DIG " << x2 << " " << y2 << endl;
            fflush(stdout);
            cin >> status;
        }
        else{
            cout << "DIG " << x1 << " " << y2 << endl;
            fflush(stdout);
            cin >> status;
            cout << "DIG " << x2 << " " << y1 << endl;
            fflush(stdout);
            cin >> status;
        }
    }
}