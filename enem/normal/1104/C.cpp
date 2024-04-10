#include <iostream>
#include <string>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int  f1=0,f2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s.at(i)=='0'&&f1==0) {cout<<"1 3\n";f1++;}
        else if(s.at(i)=='0'&&f1==1) {cout<<"3 3\n"; f1--;}
        else if(s.at(i)=='1'&&f2==0) {cout<<"3 1\n"; f2++;}
        else if(s.at(i)=='1'&&f2==1) {cout<<"3 3\n"; f2--;}
    }

    return 0;
}