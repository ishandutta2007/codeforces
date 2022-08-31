# require 'set'

n = gets.split.map(&:to_i)[0]
a = gets.split.map(&:to_i)

even = a.select {|item|item % 2 == 0}
n_e = even.length
n_o = n - n_e
if n_e >= n_o then
	print n_o
else
	x = (n_o - n_e) / 3
	print n_e + x
end
# print even.length

# if (a.take(l - 1) == b.take(l - 1) && a.drop(r) == b.drop(r) && a1 == b1) then
# 	puts "TRUTH"
# else
# 	puts "LIE"
# end