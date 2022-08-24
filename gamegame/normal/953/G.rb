r=->{gets.split.map &:to_i}
n=r[]
a=r[]
b=a.count{|_|_%2==1}
m=n.first
if b >= m-b
   p m-b+(b-m+b)/3
else
   p b
end