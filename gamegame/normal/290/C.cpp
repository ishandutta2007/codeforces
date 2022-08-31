#include<iostream>
using namespace std;
int main(){
    double tux;
    cin >> tux;
    double foo=0;
    double bar=0;
    double baz=0;
    double quz=1;
    for(;tux!=0;tux--){
        double pur;
        cin >> pur;
        foo=foo+pur;
        bar=bar+1;
        if(max(foo*quz,bar*baz)==foo*quz){
            baz=foo;
            quz=bar;
        }
    }
    cout << baz/quz << endl;
}