#include <iostream>
#include <cmath>
using namespace std;
bool win(string a,string b){
	if(a=="rock"&&b=="scissors")return 1;
	if(a=="scissors"&&b=="paper")return 1;
	if(a=="paper"&&b=="rock")return 1;
	return 0;
}
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(win(a,b)&&win(a,c))cout<<"F";
    else if(win(b,a)&&win(b,c))cout<<"M";
    else if(win(c,a)&&win(c,b))cout<<"S";
    else cout<<"?";
}