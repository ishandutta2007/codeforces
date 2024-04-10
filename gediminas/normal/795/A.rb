n,c1,c2 = gets.split.map{|_|_.to_i}
suag = gets.split("")
sum = suag.map { |a| a.to_i }.inject(0){|sum,x| sum + x }

ats = 3000000000000000000000000000

def min(*values)
 values.min
end


for a in 1..min(sum,n)
    did = n%a
    maz = a - did
    mazd = (n-a) / a
    didd = mazd + 1
	ats = min(ats, a*c1+c2*maz*mazd * mazd + c2*did*didd *didd)
end

puts ats