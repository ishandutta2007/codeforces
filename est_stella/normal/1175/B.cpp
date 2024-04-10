#include<bits/stdc++.h>
using namespace std;

int l;
unsigned long long k, cnt, x, Int = (1LL << 32) - 1;
string s;
bool over;
stack<long long> S;
vector<long long> sum;

int main() {
    std::ios_base::sync_with_stdio(false);

    cin >> l;

    for(int i=0; i<l; i++) {
        cin >> s;

        if(s == "for") {
            cin >> k;
            S.push(k);
            sum.push_back(0);
        }
        if(s == "end") {
            sum[sum.size()-1] *= S.top();
            S.pop();

            if(sum.size() >=2 ) sum[sum.size()-2] += sum[sum.size()-1];
            else x += sum[sum.size()-1];
            sum.pop_back();
        }
        if(s == "add") {
            if(sum.size()) {
                sum[sum.size()-1]++;
            }
            else x++;
        }

        if(x > Int || (sum.size() && sum[sum.size()-1] > Int)) {
            over = true;
            break;
        }
    }

    if(over) printf("OVERFLOW!!!");
    else printf("%lld\n", x);
}