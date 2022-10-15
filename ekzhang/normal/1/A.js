var ipt = readline().split(' ');
var n = parseInt(ipt[0]);
var m = parseInt(ipt[1]);
var a = parseInt(ipt[2]);
print(Math.ceil(n / a) * Math.ceil(m / a));