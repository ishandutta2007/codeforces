    
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;


int n, T;
double p[5002];
int t[5002];;
double s[5001][5001];
//double s1[5001][5001];
double k[5001];
double k1[5001];
double ans = 0.0;


void dp() {
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        k[0] = 1.0;
        for (int j = 1; j <= T; j++) {
            k[j] = k[j - 1] * (1 - p[i]);
        }
        double sum = 0.0;
        for (int j = 1; j <= T; j++) {
            if (j - 1 >= t[i] - 1 && t[i] - 1 >= 1) {
                sum -= s[i - 1][j - t[i]] * k[t[i] - 2];
            }
            sum *= k[1];
            if (t[i] - 1 >= 1) {
                sum += s[i - 1][j - 1];
            }   
            s[i][j] += (j >= t[i] ? s[i - 1][j - t[i]] * k[t[i] - 1]: 0.0);
           // cout << (j >= t[i] ? s[i - 1][j - t[i]] * k[t[i] - 1]: 0.0) << endl;
            s[i][j] += sum * p[i];
            ans += s[i][j];
                //cout << i << ' ' << j << ' ' << s[i][j] * i * k[T - j] << endl;
            //printf("%.12lf\n", sum);
        }
    }
}



// void dp1() {
//     s1[0][0] = 1;
//     for (int i = 1; i <= n; i++) {
//         double k[6000];
//         k[0] = 1.0;
//         for (int j = 1; j <= T; j++) {
//             k[j] = k[j - 1] * (1 - p[i]);
//         }
//         for (int j = 1; j <= T; j++) {
//             s1[i][j] += (j >= t[i] ? s1[i - 1][j - t[i]] * k[t[i] - 1]: 0.0);
//             for (int k1 = 1; k1 < t[i]; k1++) {
//                 if (j >= k1) {
//                     s1[i][j] += p[i] * k[k1 - 1] * s1[i - 1][j - k1]; 
//                 }   
//             }
//         }
//     }
// }



int main() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        p[i] = a;
        t[i] = b;
        p[i] /= 100.00;
    }
    dp();
    // double ans = 0.0;
    // for (int i = 0; i <= n; i++) {
    //     k[0] = 1.0;
    //     for (int j = 1; j <= T; j++) {
    //         k[j] = k[j - 1] * (1 - p[i + 1]);
    //     }
    //     for (int j = 0; j <= T; j++) {
    //         if (i == n || T - j < t[i + 1]) {
    //             ans += s[i][j] * i * k[T - j];
    //             //cout << i << ' ' << j << ' ' << s[i][j] * i * k[T - j] << endl;
    //         }
    //     }
    // }
    printf("%.10lf\n", ans);
    return 0;
}